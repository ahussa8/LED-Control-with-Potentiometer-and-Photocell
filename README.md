# LED Control with Potentiometer and Photocell – ME 331 Project 2

This Arduino-based project controls six LEDs using a potentiometer, with conditional activation based on light levels detected via a photocell. LEDs light up incrementally as the potentiometer is turned clockwise—but only when ambient light is low.

## 🔧 Components

- Arduino Uno
- 6 LEDs (any color)
- 6 resistors (220–330Ω for LEDs)
- 1 potentiometer
- 1 photocell (LDR)
- 1 resistor (10kΩ for LDR voltage divider)
- Breadboard and jumper wires

## 🔄 Functionality Overview

- The **potentiometer** controls how many LEDs are turned on:
  - Fully CCW → All LEDs OFF
  - Fully CW → All LEDs ON
  - Mid-position → ~3 LEDs ON
- The **photocell** ensures LEDs only light when it’s dark:
  - If too bright → LEDs stay OFF
  - Serial monitor displays “too bright”
- Serial monitor is used to verify photocell and potentiometer readings during development.

## 💡 Logic Breakdown

1. **Potentiometer Reading:**
   - Mapped to 6 LED levels.
   - Read via `analogRead()` and scaled accordingly.

2. **Photocell Check:**
   - Photocell value is read via another analog pin.
   - A threshold is determined experimentally (~<500 in dark).
   - LEDs are enabled only if the reading is below the threshold.

3. **Serial Output:**
   - Displays “too bright” when the room is not dark enough.

## 🧪 Features

- ✅ Responsive LED feedback based on potentiometer input
- ✅ Ambient light check for conditional activation
- ✅ Real-time debugging with Serial Monitor
- ✅ Smooth LED ramp-up and ramp-down as pot rotates

## 📂 Submission Files

- `led_photocell_pot_control.ino`: Arduino sketch
- `project_demo_video.mp4`: Demo of both lighting and ambient blocking behavior

## 🖼️ Circuit Connections

| Component     | Arduino Pin        |
|---------------|--------------------|
| Potentiometer | A0                 |
| Photocell     | A1                 |
| LEDs          | D3 to D8 (one per LED) |

## 📌 Notes

- Light threshold may vary depending on environment; tune via serial monitor.
- Ensure the resistor for the photocell is placed correctly to form a voltage divider.
- Use `map()` to convert pot values (0–1023) to number of LEDs.

---

Feel free to reach out if you’d like help with the `.ino` sketch too!
