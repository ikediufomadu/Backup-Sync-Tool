# 🔄 Backup‑Sync‑Tool

A lightweight command‑line tool for automating file backups and synchronization on **Windows**.

---

## 🧩 Features

- **Recursive** backup of files and directories from a source to a destination.
- Handles **multiple file types** (`.txt`, `.log`, `.db`, `.csv`, etc.).
- Uses **Windows APIs** to resolve special folders (e.g. `%USERPROFILE%`, `Documents`) dynamically.
- **Selective sync**: process only files that have been added or modified since the last run.
- Clean, **modular console UI** for interaction and feedback.
- **Error handling**: logs failures and continues to the next file, ensuring resilience.

---

## 🚀 Getting Started

### Prerequisites

- Windows 10+ (with Win32 API access)
- A modern C++ compiler (e.g., Visual Studio 2019 or newer)

### Installation

1. Clone the repo:
   ```bash
   git clone https://github.com/ikediufomadu/Backup-Sync-Tool.git
   cd Backup-Sync-Tool
   ```
2. Open the project in Visual Studio
3. Run the program through Visual Studio

### 🛠️ How It Works
Folder resolution
Uses Windows native APIs to translate environment variables and resolve special folders.

Recursive traversal
Scans all files and subfolders in the source directory.

Change detection
Compares last-modified timestamps to detect changes since the previous sync.

File copying
Copies updated files to the target, preserving relative structure.

Error management
Continues on failures and reports issues at the end.
