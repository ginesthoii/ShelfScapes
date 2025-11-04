![WIP](https://img.shields.io/badge/status-Work_in_Progress-yellow?style=for-the-badge&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-Compatible-blue?style=for-the-badge)

# Shelfscapes

**Shelfscapes** is a hybrid of art, engineering, and world-building — a maker’s journey into the small and the strange.  
Each build is a **book nook**: a miniature diorama that slides between books and lights up a world within your shelf.

From Diagon Alley’s glow to Rivendell’s calm, these are **self-contained environments** powered by careful wiring, coded light behaviors, and deliberate craftsmanship.

---

## Purpose

This repository serves as both **portfolio** and **toolkit** — meant to help others (and your future self) build immersive, safe, and reproducible book nooks.

### You’ll find:
- **Design & Documentation:** CAD exports, sketches, laser-cut files, and texture maps.  
- **Electronics:** Safe 5 V lighting layouts, Arduino/ESP microcontroller code, and sensor automation.  
- **Security-Minded Design:** Proper wire gauge use, power isolation, and component labeling for long-term reliability.  
- **Creative Experimentation:** Structured folders, version control for materials, and build reproducibility.

---

## Repository Structure
```
Shelfscapes/
├── nooks/           # Finished fandom builds (Diagon Alley, Rivendell, etc.)
├── readiculous/     # Experimental or humor builds (mad science, surreal)
├── _shared/         # Common assets: STL files, textures, lighting modules
├── lighting/        # Arduino .ino sketches and wiring diagrams
├── docs/            # Build logs, BOMs, diagrams, and design references
└── README.md
```

---

## Book Nook Lighting System

Each nook integrates its own **BookNook Lighting Controller** — reusable Arduino logic with plug-in `.ino` modules for:

| Module | Effect | Ideal Scene |
|--------|---------|-------------|
| `CandleFlicker.ino` | Simulated flame | Medieval tavern / library |
| `BreathingLight.ino` | Pulsing ambient glow | Magical or sci-fi |
| `MotionTrigger.ino` | PIR-activated lighting | Display shelves |
| `DayNightCycle.ino` | Automatic fade patterns | Outdoor scenes |
| `UniversalController.ino` | Multi-mode toggle | Multi-scene builds |

Powered safely via USB (5 V) or rechargeable pack, each script is modular and sensor-ready.

---

## Materials & Tools

- 3 mm birch plywood or MDF (laser-cut or hand-assembled)  
- 5 V LED strips / fairy lights / single diodes  
- Arduino Nano / ESP32 (depending on effect complexity)  
- Optional: LDR, PIR sensor, potentiometer mode selector  
- Finishes: acrylic paint, dry brushing, matte sealant  

---

## Design Philosophy

**Shelfscapes** balances artistry with engineering repeatability:
- Every nook is reproducible from open design files.
- Every light effect is modular and interchangeable.
- Every assembly prioritizes safety, repairability, and longevity.

The goal is not just to make something beautiful — it’s to make something you can maintain, improve, and pass on.

---

## Project Log

| Date | Update | Notes |
|------|---------|-------|
| **Nov 2025** | Initial repo setup (`Shelfscapes` + `_shared/lighting/`) | Added universal Arduino controller, wiring SVG. |
| **Nov 2025** | Created first modular nook structure | Interchangeable front panels, test cut in plywood. |
| **Dec 2025** *(planned)* | Add Diagon Alley prototype | Focus: LED warmth, motion-activated signage. |
| **Q1 2026** *(planned)* | Build “Westeros Archive” nook | Integration with ambient sound + smart dimming. |
| **Future** | Document safe 5 V power chaining across shelf | Optional current limiter and inline fuse module. |

---

## Getting Started

1. Clone this repo:
   ```bash
   git clone https://github.com/gineshoii/Shelfscapes.git
2.	Open /lighting/BookNookLighting_UniversalController.ino in Arduino IDE.
3.	Upload to Arduino Nano or ESP32.
4.	Connect LED strip → pin 9, PIR sensor → pin 2, LDR → A0.
5.	Power via USB (5 V 1A).
```

Future Integrations
	•	BLE control (ESP32) for ambient scene switching.
	•	Environmental sensors for temperature/reactive lighting.
	•	Voice or gesture-triggered interactions.
	•	Optional “ShelfCloud” dashboard for logging light cycles and uptime.

