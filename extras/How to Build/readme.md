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

For a full assembly demo, watch the **[Build Video](https://youtu.be/_t9MZKi8byM?si=ihr77ZkaLHi7A_hr&t=212)**.

### Recommended order

1) **Solder headers on all PCBs and modules**

<img align="right" width="360" alt="Header soldering" src="https://github.com/KravitzLabDevices/TumbleFeeder/blob/main/How%20to%20Build/Photos/IMG_4614%20(1).jpg?raw=true" />

- Solder all pin headers onto the custom PCBs and each module.
- Keep pins vertical; use a breadboard or third-hand tool for alignment.

> **Note:** The **RTC board** is the only module that uses **stacking headers**.

<br clear="both" />

---

2) **Install modules onto the main PCB**

<img width="640" alt="Assembly reference" src="https://github.com/user-attachments/assets/a6888589-f7cd-46b5-8550-a69b7f8e138a" />

- Seat each module on the header footprint matching its silkscreen.
- Double-check orientation and clearance before soldering.

---

3) **Assemble the tumbler (touch board + JST lead)**

Jump to **1:54** in the **[Build Video](https://youtu.be/_t9MZKi8byM?feature=shared&t=114)**.

<img align="right" width="320" alt="Touch board wiring" src="https://github.com/user-attachments/assets/5fce34d3-263c-495a-9cff-db253f00a2b3" />

- Solder the **JST-PH** connector to the **touch adapter board**.
- Plug a **2-pin JST lead** into the connector.
- Remove the unused cable on the connector.
- **Cable length tip:** If the red wire is too short, you can repurpose extra black lead as an **extension for the red line**. Use heat-shrink and solder the staggered splices.

<br clear="both" />

---

4) **Attach components to the 3D-printed body**

Jump to **3:32** in the **[Build Video](https://youtu.be/_t9MZKi8byM?si=ihr77ZkaLHi7A_hr&t=212)**.

<img width="353" height="344" alt="Mounting into the printed body" src="https://github.com/user-attachments/assets/5e5b75b2-e34f-4623-a201-45259496f749" />

- Dry-fit first to confirm cable routing and connector access.
- Mount the main PCB, touch board, and wiring harness; avoid pinching cables.
- Verify clearance for moving parts before final fasteners.


---

## 4) Flash and test

Jump to **7:19** in the **[Build Video](https://youtu.be/_t9MZKi8byM?feature=shared&t=469)** for flashing and validation.

### Required Arduino libraries
<img align="right" width="496" height="255" alt="Libraries screenshot"
     src="https://github.com/user-attachments/assets/3c8d73ed-6d71-4cb3-8a98-bc16a7ef795e" />

The firmware expects the following libraries:

- **Servo — `Servo.h`** — Michael Margolis, Arduino  
- **Wire — `Wire.h`** — Included with *Arduino AVR Boards* (Boards Manager)  
- **RTClib — `RTClib.h`** — Adafruit  
- **Arduino Low Power — `ArduinoLowPower.h`** — Arduino  
- **SPI — `SPI.h`** — Included with *Adafruit SAMD Boards* (Boards Manager)  
- **SdFat — `SdFat.h`** — Bill Greiman  
- **Adafruit GFX — `Adafruit_GFX.h`** — Adafruit  
- **Time — `TimeLib.h`** — Michael Margolis  
- **FlashStorage — `FlashStorage.h`** — Various Authors  
- **Adafruit FreeTouch — `Adafruit_FreeTouch.h`** — Adafruit  
- **Adafruit SHARP Memory Display — `Adafruit_SharpMem.h`** — Adafruit

<br clear="both" />

---

### Toolchain setup (Boards Manager)

<img width="802" height="528" alt="Boards Manager"
     src="https://github.com/user-attachments/assets/9ba3cf50-a338-421b-b639-3ce219a85c6a" />

1. **Add Adafruit’s Board Manager URL**  
   Arduino IDE → **File → Preferences → Additional Boards Manager URLs** → add: "https://adafruit.github.io/arduino-board-index/package_adafruit_index.json"
2. **Install board package**  
**Tools → Board → Boards Manager…** → search “Adafruit SAMD” → **Install**.
3. **Select your board and port**  
**Tools → Board** → choose your *Adafruit Feather M0* (or the specific SAMD board).  
**Tools → Port** → choose the corresponding COM/tty device.

---

### Flash the firmware

1. Open the sketch in Arduino IDE.
2. Plug your board into your computer via a micro USB cable and double-tap the reset button on the board.
3. Verify the correct **Board** and **Port** (see above).  
4. Click **Upload**. For first-time flashing or if the upload fails, double-tap reset to enter bootloader mode and upload again.

---

### Set the RTC (DS3231)

To initialize the clock, load **File → Examples → RTClib → ds3231** and upload. This sets the RTC using the sketch’s compile time.  

<img width="731" height="923" alt="image" src="https://github.com/user-attachments/assets/4049c554-0c02-4313-91e6-9d546135834e" />

- On Feather M0/SAMD boards, ensure the correct board package is installed and the right COM port is selected.
- If flashing fails mid-way, double-tap reset to enter bootloader mode and retry upload.

<br clear="both" />
