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
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/ead0b8ae-789f-4a89-abf3-f5b214b59780">
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/ef08b7e9-5da3-4675-8bed-819a188ddfd0">
  <img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/904aebc2-48de-425a-8c07-211c2ee99e63">
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/42c5b5ad-2fc5-4338-b35a-eaee24774c3f">
  <img width="49%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/46db259f-010f-40bf-972f-957ca37790a1">
</p>

## The Electrical Box:
<p align="center" width="100%">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/68522dd5-0d06-454a-a67b-301b247f839e">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/b7e2f92a-96b9-4518-a948-fd2318378ce4">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/854512c4-c020-4bea-bfe3-a2c06d476576">
  <img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/44935144-129c-4adc-9662-117a5c6fd14e">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/52d1c8bb-e6c3-40dd-8812-0ea8f305d82b">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/8541f4a3-8073-4318-9bfe-5cec8382e189">
  <img width="32%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/655ed1fb-2682-4776-bac4-f635e626d567">
  <img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/9e3172ce-6052-4ac1-9c9c-e15d62f2aa08">
</p>

## User Interface:
<img width="100%" src="https://github.com/MoaRajj/Coating_Machine/assets/93192572/f2b57448-e897-4359-ad77-f7040866f87f">




