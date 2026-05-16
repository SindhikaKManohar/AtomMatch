# AtomMatch — Low-Latency Trading Engine Simulator 

AtomMatch is a simplified high-frequency trading (HFT) engine simulator built in C++17 to explore low-latency systems, exchange architecture, and performance-oriented software engineering.

The project was developed incrementally to understand how trading systems process orders, communicate over networks, and optimize performance under high message throughput.

---

##  Features

* Object-Oriented Order Management System
* Buy/Sell Matching Engine
* TCP Client-Server Communication
* UDP Market Data Simulation
* Binary Packet Transmission
* Latency Measurement using High-Resolution Timestamps
* Throughput Flood Testing
* Memory Pool Optimization Experiments
* Multithreading Fundamentals using std::thread

---

##  Technologies Used

* C++17
* STL
* Winsock2
* TCP/IP
* UDP
* std::chrono
* std::thread
* Atomics & Mutexes
* Binary Serialization Concepts

---

##  Project Architecture

The project is divided into multiple learning stages:

### Stage 1 — Core OOP System

* Order and Trade classes
* Modular header/source file design

### Stage 2 — Generic Trading Components

* Template-based order system
* Multi-asset support

### Stage 3 — Validation & Safety

* Exception handling
* Runtime validation

### Stage 4 — Matching Engine

* Buy/Sell order book
* Price matching logic

### Stage 5 — Networking

* TCP client/server communication
* UDP packet transmission
* Binary order packets

### Stage 6 — Latency Engineering

* Nanosecond timestamping
* Throughput flood testing
* Latency benchmarking

### Stage 7 — Memory Optimization

* Memory pool experiments
* Allocation overhead comparison
* Cache locality concepts

---

##  Benchmark Experiments

AtomMatch includes several educational benchmarking experiments related to:

* packet throughput
* latency measurement
* memory allocation overhead
* lightweight in-memory order processing

These experiments were performed locally on consumer hardware for learning low-latency systems concepts.

---

##  How to Build

Compile using g++:

```bash
g++ filename.cpp -o output -lws2_32
```

Example:

```bash
g++ latency_server.cpp -o lserver -lws2_32
```

---

##  Learning Goals

This project was built to explore:

* low-latency systems
* systems programming
* computer networking
* exchange architecture
* performance optimization concepts
* modern C++ development

---

##  Future Improvements

* Lock-Free Ring Buffers
* Multi-threaded Matching Engine
* Advanced Order Book Structures
* CPU Affinity Experiments
* Linux epoll-based Networking
* Performance Profiling
* Market Data Replay Simulation

