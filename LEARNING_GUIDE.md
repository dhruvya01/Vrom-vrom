# 🏎️ Vrom Vrom - Beginner's Learning Guide & Development Log

Welcome to your game development learning guide! This file is updated with every milestone to explain **how everything works**, **why we write specific code**, and **what concepts mean in plain English**.

---

## 📚 Core Game Development Concepts (Beginner 101)

### 1. What is a Game Engine?
Think of **Unreal Engine 5** as a digital movie set + physics simulator + software compiler all in one. Instead of writing graphics code to draw every pixel on your screen from scratch, Unreal Engine gives you lighting, 3D world tools, sound managers, and physics out of the box.

### 2. C++ vs. Blueprints
* **C++ (Code):** The underlying blueprint of instructions written in text. It runs extremely fast on your computer's processor. This is where we write core car math, physics, gear ratios, and logic.
* **Blueprints (Visual Scripting):** Unreal Engine's visual drag-and-drop system. It allows you to link 3D car models, colors, sounds, and visual effects to the C++ code without writing text.
* **Our Strategy:** We write the foundation in C++ for maximum performance and clean architecture, and you hook up the 3D models and controls visually in Blueprints!

### 3. What is Chaos Vehicles?
Unreal Engine 5 has a built-in physics plugin called **Chaos Vehicles**. Instead of coding wheels, suspension springs, and friction manually, Chaos Vehicles lets us create a vehicle pawn where Unreal calculates:
* Wheel rotation and friction against the road.
* Suspension compression when jumping or turning.
* Weight transfer when accelerating or braking.

### 4. What is Enhanced Input?
In modern games, pressing the `W` key shouldn't just mean "move forward". What if you plug in a steering wheel or a PS5 controller later?
**Enhanced Input** abstracts controls into "Actions":
* `IA_Throttle`: Means "Accelerate". We map the `W` key on a keyboard, or the Right Trigger `R2` on a controller, to trigger this same action!

---

## 🛠️ Milestone 1 Breakdown: The Foundation

### What Files Were Created & Why?

1. **`DrivingSimulator.uproject`**
   * **What it is:** The master config file for your project.
   * **Why we need it:** Tells Unreal Engine 5 which engine version to use (`5.8`) and which plugins to load (`ChaosVehiclesPlugin`).

2. **`Source/DrivingSimulator/DrivingSimulatorVehicle.h` & `.cpp`**
   * **What it is:** The C++ master class for your car.
   * **How it works:**
     * It attaches a **SpringArm** (an invisible selfie-stick) and a **Camera** behind the car for the chase camera view.
     * It listens for input actions (Throttle, Brake/Reverse, Steering, Handbrake, Reset).
     * When you press `W`, it calls `SetThrottleInput(Value)`, which tells Chaos Vehicles to apply engine power to the drive wheels!
     * When you press `R`, it teleports the car 200 units up in the air, resets its rotation to upright, and zeroes out any spinning velocity (Reset Vehicle).

3. **`Source/DrivingSimulator/DrivingSimulatorGameMode.h` & `.cpp`**
   * **What it is:** The "Rules & Spawner" of the level.
   * **Why we need it:** Tells the game: *"Whenever a player clicks Play, automatically spawn our custom DrivingSimulatorVehicle and put the player in the driver's seat!"*

---

## 📝 Progress Log & Next Steps

| Milestone | Status | What Was Built | Key Learning |
| :--- | :---: | :--- | :--- |
| **Milestone 1** | 🔄 *In Progress* | Vehicle C++ Foundation, Enhanced Input Setup, Chase Camera, Reset Function | How C++ vehicle physics connects to UE5 and Blueprints |
| **Milestone 2** | ⏳ *Pending* | Import 3D Car Model, Assign Wheel Blueprints, Basic Test Track | How 3D `.fbx` models & materials work inside Unreal Editor |
| **Milestone 3** | ⏳ *Pending* | Manual Transmission, RPM, Torque Curve, Clutch Physics | Engine physics formulas & gear ratio mechanics |

---

> 💡 **Tip:** Whenever we add a new system (clutch, gear ratios, audio, UI), this guide will be updated with simple explanations so you learn how game engines work as we build!
