#include <iostream>
#include <string>

class Job {
public:
    int id;
    std::string userName;
    int numPages;

    Job() : id(0), userName(""), numPages(0) {}
    Job(int jobId, std::string name, int pages) : id(jobId), userName(name), numPages(pages) {}
};

template <typename T>
class qNode {
public:
    T data;
    qNode<T>* next;
};

class Printer {
private:
    qNode<Job>* frontPtr;
    qNode<Job>* backPtr;

public:
    Printer() {
        frontPtr = nullptr;
        backPtr = nullptr;
    }

    ~Printer() {
        while (frontPtr != nullptr) {
            qNode<Job>* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
    }

    void addJob(Job newJob) {
        qNode<Job>* newNode = new qNode<Job>;
        newNode->data = newJob;
        newNode->next = nullptr;

        if (frontPtr == nullptr) {
            frontPtr = newNode;
            backPtr = newNode;
        } else {
            backPtr->next = newNode;
            backPtr = newNode;
        }
        std::cout << "Added Job #" << newJob.id << " (" << newJob.numPages 
                  << " pages) submitted by " << newJob.userName << "." << std::endl;
    }

    void processJob() {
        if (frontPtr == nullptr) {
            std::cout << "No pending print jobs in the queue." << std::endl;
            return;
        }

        qNode<Job>* deleteNode = frontPtr;
        Job currentJob = deleteNode->data;

        std::cout << "Processing Job #" << currentJob.id << ": Printing " 
                  << currentJob.numPages << " pages for user '" << currentJob.userName 
                  << "'Done!" << std::endl;

        if (frontPtr == backPtr) {
            frontPtr = nullptr;
            backPtr = nullptr;
        } else {
            frontPtr = frontPtr->next;
        }

        delete deleteNode;
    }

    bool hasJobs() {
        return frontPtr != nullptr;
    }
};

int main() {
    Printer officePrinter;

    std::cout << "=== Office Workers Submitting Print Requests ===" << std::endl;
    officePrinter.addJob(Job(101, "Clark", 12));
    officePrinter.addJob(Job(102, "Ken", 5));
    officePrinter.addJob(Job(103, "Carl", 27));
    std::cout << std::endl;

    std::cout << "==== Printer Processing Queue (First-Come, First-Served) ====" << std::endl;
    while (officePrinter.hasJobs()) {
        officePrinter.processJob();
    }

    return 0;
}

