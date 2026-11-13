# Sense and Respond

## 1. System purpose

- **Problem and real-world context:** Fighting game input notation is obtuse and often a turn-off for newcomers.
- **Intended user:** People in the fighting game community, especially new players.
- **What physical condition should your system monitor?** The direction of the analog stick.
- **How will the system's response help the user?** By allowing them to practice the notation corresponding to common inputs
  
## 2. System design

### System diagram

```(AnalogStick.x, AnalogStick.y) → conversion to polar coordinates, angle theta → round theta to the nearest multiple of pi/4 = theta' → output 2pi/theta'```

### Inputs and outputs

| Device | Input or output | Arduino pin(s) | Analog or digital?  |
| --- | --- | --- | --- |
| Analog Stick | Sensor input | A0, A1 | Analog |
| LCD | Output | 3, 5, 8-11 | Digital |
| LED | Additional output | 12, 13 | Digital |

### Decision table

| Sensor reading or condition | System state | LCD display | Additional output |
| --- | --- | --- | --- |
| (0, 0) | Neutral | 5 - NEUTRAL | LED on |
| (-1, 0) | Left | 4 - LEFT | LED off |

### Libraries

> Identify each library your Arduino sketch uses and briefly explain what it helps the program do. Add rows as needed. If you used no libraries, write “None.”

| Library | What it does in your program |
| --- | --- |
| cstdio | C Standard Library functions |
| LiquidCrystal | LCD control |

## 3. Circuit design

> Upload a screenshot of your TinkerCAD circuit or a labeled circuit diagram. Show the components, Arduino pins, power, and ground connections. Replace the image path below if you use a different filename.

![Circuit diagram](circuit.png)

## 4. Testing and revision

> Test your working prototype under at least three different conditions. Include normal operation and at least two conditions that trigger a response. Record the condition or sensor reading for each test. Predict what the LCD and additional output will do, then record what you actually observe.

| Test | Condition or sensor reading | Expected response | Actual response |
| --- | --- | --- | --- |
| Normal operation | TODO | TODO | TODO |
| Condition that triggers a response | TODO | TODO | TODO |
| Condition that triggers a response | TODO | TODO | TODO |

**Revisions made to the system based on testing**

> Describe any changes you made based on your test results and test the affected behavior again. If you made no changes, explain why.

**Revision and reason:** TODO

**Result after testing the revision:** TODO

## 5. Video Demonstration

> Replace the placeholder below with a link to your video. Introduce the real-world problem, show the sensor detecting a change in physical conditions, and demonstrate how the system responds under different conditions. Use on-screen text or voice-over to explain how it works. 

[Video demonstration](https://youtube.com/)
