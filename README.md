# 🏎️ Vrom Vrom

> A high-quality, realistic 3D driving simulator built from scratch using **Unreal Engine 5** (Chaos Vehicles & Enhanced Input), designed for Mac & PC.

---

## 🌟 Overview

**Vrom Vrom** is a realistic physics-driven racing simulator focusing on true-to-life vehicle dynamics, manual clutch, engine torque curves, dynamic lighting, and high-fidelity 3D graphics.

Built modularly using **C++** and **Unreal Engine 5.8**, the project follows clean architecture principles to separate core physics and logic from visual Blueprint components.

---

## ⚡ Features & Roadmap

### 🏁 Milestone 1: The Foundation (Current)
- [x] **Chaos Vehicle C++ Core**: Powered by `AWheeledVehiclePawn`.
- [x] **Enhanced Input Architecture**: Clean mapping for Throttle, Brake/Reverse, Steering, Handbrake, and Reset.
- [x] **Chase Camera**: SpringArm + Camera follow setup.
- [x] **Vehicle Reset System**: Teleport and flip recovery logic in C++.
- [x] **Beginner Learning Guide**: Interactive documentation in `LEARNING_GUIDE.md`.

### 🏎️ Milestone 2: Vehicle Visuals & Track (Next)
- [ ] 3D Skeletal Mesh Car Import (Mustang / Police Car).
- [ ] Chaos Wheel Setup & Suspension tuning.
- [ ] Basic Test Track & Surface friction.

### ⚙️ Milestone 3: Advanced Drivetrain Physics
- [ ] Manual Transmission & Clutch simulation.
- [ ] Engine RPM curves & Torque calculation.
- [ ] Dynamic MetaSound Engine Revs & Tire Squeals.
- [ ] Cockpit View & Working Dashboard Gauges (Speedometer, Tachometer).

---

## 🛠️ Tech Stack & Requirements

* **Engine:** Unreal Engine 5.8 (ChaosVehiclesPlugin & EnhancedInput)
* **Language:** C++ / Unreal Engine Blueprints
* **IDE / Build Tools:** Xcode (macOS) / Visual Studio (Windows)
* **Target Hardware:** Mac Apple Silicon (M-Series optimized) & PC

---

## 🚀 Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/dhruvya01/Vrom-vrom.git
   ```

2. **Open in Unreal Engine 5:**
   * Double-click `DrivingSimulator.uproject`.
   * Click **Yes** when prompted to rebuild missing C++ modules.

3. **Play:**
   * Open the test map and hit **Play**!

---

## 📚 Documentation & Logs

For a step-by-step breakdown of how the C++ code works and beginner-friendly game development explanations, check out [LEARNING_GUIDE.md](file:///Users/dhruvya/DrivingSimulator/LEARNING_GUIDE.md).

---

*Created by **Dhruvya** with AI Pair Programming.* 🚀
