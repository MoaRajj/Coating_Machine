# "Coating Machine"

## Objective:
The primary objective of this project is to implement a precise coating technique within a controlled atmospheric environment.

## Methodology:
The project utilized a structure consisting of sigma profiles with a flat surface and a bridge, enabling movement in three dimensions. This structure was affixed to a spinning head with an attached polishing pad, controlled by an Arduino Mega. The Arduino Mega managed the speed, timing, and pressure points of stepper motors based on feedback from an Arduino Uno. The Uno measured applied pressure and adjusted the Aluminum plate's temperature, placed on the structure's flat surface where the coating process occurred.

The Aluminum plate was designed to secure the intended substrate film for coating using a vacuum pump. Additionally, a silicon heater and a K-type thermocouple were incorporated to maintain and monitor temperature using PID control through a relay.

To enhance the accuracy of pressure sensors (Load Cells), coil springs replaced the previous setup, situated above the sensors at each corner of the Aluminum plate.

Lastly, a Graphical User Interface (GUI) was developed using the PyQt5 and PySerial libraries in Python. This GUI facilitated seamless communication between the two Arduinos and the user, making it user-friendly and efficient to operate the entire system.

## Results:
This project yielded a versatile machine, allowing users to perform the coating technique repeatedly with adjustable parameters. The machine finds valuable applications in laboratory settings for experimenting with various chemical solutions and optimizing thermoelectric performance by altering parameters.

## Challenges:
Undertaking this project immediately after my graduation presented considerable challenges. Delving into the complexities of stepper motors was a steep learning curve, especially in achieving optimal speeds beyond typical library capabilities.

Addressing the challenge of simultaneously reading, writing, and running the motors on a single Arduino without compromising speed was demanding. It led to the realization that the most effective response involved communication between Arduinos through a Python-coded user interface.

Challenges extended beyond electronics and coding. Building the machine from scratch necessitated learning to operate diverse cutting machines like Universal Milling, Manual Lathes, and Horizontal Sawing. Furthermore, organizing, wiring, and constructing a safe electrical panel for the machine was a valuable skill acquired during this project.

## Relevance:
This project served as the catalyst for my deep-rooted passion for Automation and Control. Witnessing the culmination of hours and days of effort in a mechanism operating precisely as intended solidified my dedication to this field.
