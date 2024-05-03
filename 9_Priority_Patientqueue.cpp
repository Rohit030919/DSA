#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define a structure for Patient
struct Patient {
    string name;
    int priority;
    // Constructor for easy initialization
    Patient(string n, int p) : name(n), priority(p) {}
};

// Comparator for priority queue to prioritize lower integers (higher priority)
struct ComparePriority {
    bool operator()(const Patient& p1, const Patient& p2) {
        return p1.priority > p2.priority;
    }
};

// Function to add a patient to the queue
void enqueue(priority_queue<Patient, vector<Patient>, ComparePriority>& pq, string name, int priority) {
    pq.push(Patient(name, priority));
}

// Function to delete a patient from the queue (treat a patient)
void dequeue(priority_queue<Patient, vector<Patient>, ComparePriority>& pq) {
    if (pq.empty()) {
        cout << "The queue is empty." << endl;
        return;
    }
    Patient treated = pq.top();
    pq.pop();
    cout << "Treating patient: " << treated.name << " (Priority: " << treated.priority << ")" << endl;
}

// Function to display all patients in the queue
void display(priority_queue<Patient, vector<Patient>, ComparePriority> pq) {
    if (pq.empty()) {
        cout << "The queue is empty." << endl;
        return;
    }
    while (!pq.empty()) {
        Patient p = pq.top();
        cout << "Patient: " << p.name << " - Priority: " << p.priority;
        switch (p.priority) {
            case 1: cout << " (Serious)"; break;
            case 2: cout << " (Non-serious)"; break;
            case 3: cout << " (General Checkup)"; break;
            default: cout << " (Unknown Priority)"; break;
        }
        cout << endl;
        pq.pop();
    }
}

int main() {
    priority_queue<Patient, vector<Patient>, ComparePriority> pq;

    enqueue(pq, "John Doe", 2);
    enqueue(pq, "Jane Smith", 1);
    enqueue(pq, "Alice Johnson", 3);
    enqueue(pq, "Bob Brown", 1);

    cout << "Displaying all patients in priority order:" << endl;
    display(pq);

    cout << "\nTreating a patient:" << endl;
    dequeue(pq);

    cout << "\nDisplaying remaining patients in priority order:" << endl;
    display(pq);

    return 0;
}
