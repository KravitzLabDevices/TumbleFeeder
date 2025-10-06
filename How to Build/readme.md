# Build the TumbleFeeder

A fast, repeatable build you can complete with common tools and off-the-shelf parts.

**Quick links:**  
- ▶️ **[Build Video (YouTube)](https://www.youtube.com/watch?v=_t9MZKi8byM)**  
- 🧩 **[3D Parts (STL)](https://github.com/KravitzLabDevices/TumbleFeeder/tree/main/How%20to%20Build/3D_Design)**  
- ✏️ **[Editable TinkerCAD](https://www.tinkercad.com/things/1IhfIT78Xpz-tumble-feeder-sept2024)**  
- 🖥️ **[Electronics (Eagle .brd/.sch)](https://github.com/KravitzLabDevices/TumbleFeeder/tree/main/How%20to%20Build/Electronics)**  
- 📋 **[BOM (Google Sheet)](https://docs.google.com/spreadsheets/d/167cMoID8Alf8LLFngqACXI5k8x5zef9LXBQ9bw7NaI0/edit?gid=0#gid=0)**

---

## Build Steps

1. **3D print the four parts**  
2. **Populate the PCB(s)**  
3. **Assemble the TumbleFeeder**  
4. **Flash and test the device**  
→ Prefer video? Watch the **[Build Video](https://www.youtube.com/watch?v=_t9MZKi8byM)**.

---

## 1) Print the 3D parts

<img align="right" width="360" alt="Printed parts" src="https://github.com/user-attachments/assets/f3622f2b-b8e6-4959-ae0e-69637996c6e7" />
  
- **Download STLs:**  
  https://github.com/KravitzLabDevices/TumbleFeeder/tree/main/How%20to%20Build/3D_Design  
- **Material/Printer:** PLA+ on a Bambu X1C works well (others are fine).  
- **No printer?** Services like Shapeways will work.  
- **Editable model:**  
  https://www.tinkercad.com/things/1IhfIT78Xpz-tumble-feeder-sept2024  

<sub><br clear="both"></sub>

---

## 2) Populate the PCB

Order the two custom PCBs (OSH Park badges below) or build from the Eagle files.

**Files:** https://github.com/KravitzLabDevices/TumbleFeeder/tree/main/How%20to%20Build/Electronics

**PCBs:**
1. **Main PCB**  
   <img width="100%" alt="Main PCB render" src="https://github.com/user-attachments/assets/22cf06b9-baf9-44b1-90c9-bc0355a9fac0" />  
   <a href="https://oshpark.com/shared_projects/G0He9rRP">
     <img alt="Order from OSH Park" src="https://oshpark.com/assets/badge-5b7ec47045b78aef6eb9d83b3bac6b1920de805e9a0c227658eac6e19a045b9c.png">
   </a>

2. **Touch adapter PCB**  
   <img width="180" alt="Touch PCB" src="https://github.com/user-attachments/assets/d805b8a3-02ef-410a-bc81-43f006afd9fd" />  
   <a href="https://oshpark.com/shared_projects/q8TvJ7jU">
     <img alt="Order from OSH Park" src="https://oshpark.com/assets/badge-5b7ec47045b78aef6eb9d83b3bac6b1920de805e9a0c227658eac6e19a045b9c.png">
   </a>

**Parts:** See the **[BOM](https://docs.google.com/spreadsheets/d/167cMoID8Alf8LLFngqACXI5k8x5zef9LXBQ9bw7NaI0/edit?gid=0#gid=0)**.  
**Soldering walkthrough:** in the **[Build Video](https://www.youtube.com/watch?v=_t9MZKi8byM)**.

---

## 3) Assemble the TumbleFeeder

For a full assembly demo, jump to **1:54** in the **[Build Video](https://youtu.be/_t9MZKi8byM?feature=shared&t=114)**.

**Recommended order:**
1. Solder **all headers** onto the custom PCBs and individual modules.  
   <img width="640" alt="Header soldering" src="https://github.com/KravitzLabDevices/TumbleFeeder/blob/main/How%20to%20Build/Photos/IMG_4614%20(1).jpg?raw=true" />
   > **Note:** The **RTC board** is the only module that uses **stacking headers**.

2. Install modules onto the **main PCB** as shown below.  
   <img width="640" alt="Assembly reference" src="https://github.com/user-attachments/assets/a6888589-f7cd-46b5-8550-a69b7f8e138a" />

---

## 4) Flash and test

Jump to **7:19** in the **[Build Video](https://youtu.be/_t9MZKi8byM?feature=shared&t=469)** for flashing and validation.

### Required Arduino Libraries
<!-- Image floats to the right; text flows on the left -->
<img align="right" width="496" height="255" alt="Libraries screenshot"
     src="https://github.com/user-attachments/assets/3c8d73ed-6d71-4cb3-8a98-bc16a7ef795e" />

**The libraries required to flash the code are listed below:**

- **Servo — `Servo.h`**  
  _by Michael Margolis, Arduino_
- **Wire — `Wire.h`**  
  _Included with Arduino AVR Boards (via Boards Manager)_
- **RTClib — `RTClib.h`**  
  _by Adafruit_
- **Arduino Low Power — `ArduinoLowPower.h`**  
  _by Arduino_
- **SPI — `SPI.h`**  
  _Included with Adafruit SAMD Boards (via Boards Manager)_
- **SdFat — `SdFat.h`**  
  _by Bill Greiman_
- **Adafruit GFX — `Adafruit_GFX.h`**  
  _by Adafruit_
- **Time — `TimeLib.h`**  
  _by Michael Margolis_
- **FlashStorage — `FlashStorage.h`**  
  _by Various Authors_
- **Adafruit FreeTouch — `Adafruit_FreeTouch.h`**  
  _by Adafruit_
- **Adafruit SHARP Memory Display — `Adafruit_SharpMem.h`**  
  _by Adafruit_


<summary><strong>Troubleshooting (common flash/test issues)</strong></summary>

- On Feather M0/SAMD boards, ensure the correct board package is installed and the right COM port is selected.
- If flashing fails mid-way, double-tap reset to enter bootloader mode and retry upload.

<br clear="both" />
