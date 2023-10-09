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

## Video:
Click on the following image to watch the video :point_down: .
<div align="center">
  
  [![Watch the video](https://img.youtube.com/vi/JpsZ2kwcEPo/hqdefault.jpg)](https://www.youtube.com/embed/JpsZ2kwcEPo)
</div>

## The Machine:
<p align="center" width="100%">
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/f1ea2b74-e4f6-4679-a421-433144c9afef">
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/694fd780-0784-405c-a7b8-11f908986287">
  <img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/3c70bd65-16b4-48d9-aab8-037fb876b3a4">
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/c67bad3e-958a-4854-a7bf-5ab420cdd817">
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/483f3f1e-7820-4d32-b32b-cc910c447a9d">
</p>

## The Electrical Box:
<p align="center" width="100%">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/3671bbec-19c7-4e05-a9fd-c9bcbd518298">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/f11d3a59-f070-4bb8-a811-b006585a20a7">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/87d1c1e0-75fc-4926-8596-0584621e1603">
  <img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/f28f04cf-b73b-4c01-a2cd-1b3d169b4311">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/7d3a183f-5a49-4a94-9aaa-d684988f3f0c">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/c0ea499d-57cf-48e6-aaf8-6da997d6e39f">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/37c132ee-df15-47d0-8d44-bb972d0fe1b5">
  <img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/bc5cb97d-de9a-4614-a5f6-610d88a57396">
</p>

## User Interface:
<img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/fe29352f-111a-41f7-aa64-f440e3c5fad5">
