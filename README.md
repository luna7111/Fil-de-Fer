# FdF
FdF is a project inside the 42 Common core. It consists on the development of a topographic map visualizer using pure C and the (very limited) MiniLibX graphic library.

<img width="2306" height="1462" alt="image" src="https://github.com/user-attachments/assets/1e86fcfb-4dee-4ad7-b723-81167dc03979" />

## Files
FdF maps should be described in a plain text file where any point in the map is written as a number, separated with spaces in a grid.
### For example this map:

<img width="984" height="723" alt="image" src="https://github.com/user-attachments/assets/82ab0bed-3d63-4c12-8f42-4f26c32ce944" />

### Should look something like:

<img width="2306" height="1462" alt="image" src="https://github.com/user-attachments/assets/3fce46d0-765f-425d-92ca-629d24ed0fa7" />

---

And the color of a point is described in hexadecimal, separated with a comma next to the point.

### The map described as:

<img width="1053" height="724" alt="image" src="https://github.com/user-attachments/assets/2ff692c1-2fa4-4207-aa72-55e4a90fd6e0" />

### Should look like:

<img width="2306" height="1462" alt="image" src="https://github.com/user-attachments/assets/13e8e265-ccfc-4436-a806-d798e5600b88" />

## Features
The program is able to render maps, rotate them around X Y and Z axis, toggle between an Axonometric/Isometric perspective and parallel perspective, zoom in and out and translate the rendered image in the screen x and y axis.

## Usage
To use the program just run it in a terminal using the map file path as an argument:
```
./fdf maps/luna/brazil.fdf
```
### Controls
Zoom in and out with the scroll wheel, rotate each axis with X, Y and Z keys, toggle the perspective with the P key, transpose the rendered image with the arrow keys.
