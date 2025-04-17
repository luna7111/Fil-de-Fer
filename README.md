# FdF
FdF is a project inside the 42 Common core. It consists on the development of a topographic map visualizer using pure C and the (very limited) MiniLibX graphic library.

![Screenshot0](https://github.com/luna7111/fdf/blob/main/images/t1_map_render.png?raw=true "A screenshot of the program rendering a map with a sea and some mountains")

## Files
FdF maps should be described in a plain text file where any point in the map is written as a number, separated with spaces in a grid.
### For example this map:

![Screenshot1](https://github.com/luna7111/fdf/blob/main/images/basic_grid_file_screenshot.png?raw=true "basic_grid.fdf screenshot")

### Should look something like:

![Screenshot2](https://github.com/luna7111/fdf/blob/main/images/basic_grid_render_screenshot.png?raw=true "basic_grid.fdf render screenshot")

---

And the color of a point is described in hexadecimal, separated with a comma next to the point.

### The map described as:

![Screenshot3](https://github.com/luna7111/fdf/blob/main/images/colored_grid_file_screenshot.png?raw=true "colored_grid.fdf screenshot")

### Should look like:

![Screenshot4](https://github.com/luna7111/fdf/blob/main/images/colored_grid_render_screenshot.png?raw=true "colored_grid.fdf render screenshot")

## Features
The program is able to render maps, rotate them around X Y and Z axis, toggle between an Axonometric/Isometric perspective and parallel perspective, zoom in and out and translate the rendered image in the screen x and y axis.
