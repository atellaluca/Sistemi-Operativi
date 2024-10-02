# 🍽️ Dining Philosophers Problem - Pthreads Implementation

![Dining Philosophers Problem](./images/dining-philosophers-problem.png)

## 📖 Overview

This repository contains an implementation of the classic **Dining Philosophers Problem** 🧠, using **Pthreads** and **semaphores** in C++. The problem showcases process synchronization, where five philosophers 🧑‍🎓 share limited resources (forks 🍴) to alternate between eating 🍝 and thinking 🤔. The solution ensures safe resource allocation and deadlock prevention 🔒.

This project is part of the **Operating Systems** course at the **University of Basilicata**, led by Professor **Domenico Daniele Bloisi** 🏛️.

## ✨ Features

- 🧩 Implements the dining philosophers problem
- 🧵 Thread management with Pthreads
- 🛡️ Synchronization using semaphores
- 📊 Displays philosopher status (thinking, eating, waiting)

## 🚀 How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/atellaluca/dining-philosophers.git
2. Compile the program:
   ```bash
   g++ -o philosophers dining-philosophers.cpp -lpthread
3. Run the executable:
   ```bash
   ./philosophers

## 🏗️ Project Structure

- `dining-philosophers.cpp`: Main source code for the project.

## 🏷️ Topics

- 🧠 dining-philosophers
- 🧵 pthreads
- 🔐 semaphores
- 🔄 synchronization
- ⚙️ multithreading
- 💻 cpp
- 🛠️ operating-systems
- 🧮 resource-management

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
