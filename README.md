# so_long_macOS
A small 2D game to learn how to work with windows, colors, events and textures. Inspired by the "42 Coding School" exercise "so_long" (October 2021).

![so_long](https://user-images.githubusercontent.com/80413516/155494401-f80fc365-a149-4cf7-bba0-c28b14634285.gif)

## Table of contents
* [Introduction](#introduction)
  * [Allowed functions](#allowed-functions)
  * [Description](#description)
  * [General rules](#general-rules)
  * [Map-file](#map-file)
* [Approach](#approach)
* [Prerequisites](#prerequisites)
* [How to launch](#how-to-launch)
* [How to play](#how-to-play)
* [Example](#example)
* [Resources](#resources)
* [Notes](#notes)


## Introduction
###### <p align="right">Next: [Approach](#approach)&emsp;&emsp;[[Contents](#table-of-contents)]</p>
### Allowed functions
open, close, read, write, printf, malloc, free, perror, strerror, exit

Aditionally all functions of the [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html#introduction-1) can be used. 

### Description
The aim of the exercise is to create a small 2D game in which the player has to collect some loot on a map, before leaving it.

### General rules
* The player’s goal is to collect all collectibles present on the map and then escape.
* The current number of movements must be displayed.
* The player must be able to move: up, down, left, right.
* The player cannot move into walls.
* The program is dosplayed in a window.
* The arrow-keys and/or the W, A, S, and D keys will be used to move around the map.
* Pressing ESC or clicking on the close button on the window’s frame must close the window and quit the program cleanly.
* As argument the program takes a [map-file](#map-file).
* If a misconfiguration of any kind is encountered in the [map-file](#map-file), the program must exit properly and return "Error\n" followed by an explicit error message.

### Map-file
* The map-file has to be of type ".ber".
* It can only consist of 5 possible characters:
  * '0' for an empty space
  * '1' for a wall
  * 'C' for a collectible
  * 'E' for a map exit
  * 'P' for the player’s starting position
* The map must be closed/surrounded by walls.
* The map must have:
  * at least one exit
  * at least one collectible
  * only one starting position
* The map has to be rectangular.

## Approach
###### <p align="right">Next: [Prerequisites](#prerequisites)&emsp;Previous: [Introduction](#introduction)&emsp;&emsp;[[Contents](#table-of-contents)]</p>

I started with reading, storing and errorchecking the [map-file](#map-file). To make sure everything worked as it is supposed to, I printed the stored data into the terminal and checked weather I get back the map-file's original content.

The main difficulty with this project for me was to get to know the [mlx-functions](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html) and to learn how they work or at least how to use them. First I learned [how to initialize mlx and open a window](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#initialization). The result is a black window. Then I tried to display pixels in different colors using [mlx_pixel_put](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_pixel_put). Once I managed this, I arranged the colored pixels to display lines, then rectangels and so on.

After that I learned [how to write pixels to an image](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#writing-pixels-to-a-image) and [how to put images to the window](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#pushing-images-to-a-window). This was the perfect function for my project, as you can also [load images](https://harm-smits.github.io/42docs/libs/minilibx/images.html#reading-images) into your program instead of drawing them pixel by pixel. The grid-like layout of the map is particularly suited to work with _tiles_. This means that each field of the map will be represented by a certain image in accordance to the map-file's definition.

My next step was to display the map within the window using different images. I use one image per [map-file](#map-file) character. For diversion it would also be possible to user various images for the same map-file character and vary them. The only exception is the player where I use different images depending on the direction it is heading, but this is something I implemented later.

Now I had to find a way to change what I see when pressing certain keys. Therefore I learned about [events](https://harm-smits.github.io/42docs/libs/minilibx/events.html#introduction) and how to [hook](https://harm-smits.github.io/42docs/libs/minilibx/events.html#hooking-into-events) into them. To see if I got it right, I startet printing the keycodes into the terminal. Then instead of printing the keycodes on key-press, I checked for the keycode instead and executed different functions, depending on the pressed key.

To get the impression of movement you can think of a flicker book, where you have an image that changes slightly page by page. Instead of pages you have a window and key-press by key-press you can put new images on top of the old ones. In my opinion it is enough to only put new images on the map-fields that change, but I guess you could also refresh the whole map each time, but I don't think that it is necessary.

## Prerequisites
###### <p align="right">Next: [How to launch](#how-to-launch)&emsp;Previous: [Approach](#approach)&emsp;&emsp;[[Contents](#table-of-contents)]</p>
Tested on macOS Catalina 10.15.7
* gcc (```sudo apt-get install gcc```)
* make (```sudo apt-get install make```)

## How to launch
###### <p align="right">Next: [How to play](#how-to-play)&emsp;Previous: [Prerequisites](#prerequisites)&emsp;&emsp;[[Contents](#table-of-contents)]</p>
Compile the program via the Makefile by using ```$ make``` in the root directory of the repository.

Run it by giving it the path to the map-file as argument (in this case the file "example.ber" within the directory "maps"):

```
$ ./so_long maps/example.ber
```

For the required map-file format see: [Map-file](#map-file)

## How to play
###### <p align="right">Next: [Example](#example)&emsp;Previous: [How to launch](#how-to-launch)&emsp;&emsp;[[Contents](#table-of-contents)]</p>
You are a fly and have to collect all the poo on the map and escape into the bright light. But be careful, there is a hungry frog who wants to eat you. If you get caught, you lose. You can create your own map, by creating a [map-file](#map-file).

### Keys
```W``` / ```ARROW-UP``` - Move upwards

```A``` / ```ARROW-LEFT``` - Move left

```S``` / ```ARROW-DOWN``` - Move downwards

```D``` / ```ARROW-RIGHT``` - Move right

```ESC``` - Exit game

## Example
###### <p align="right">Next: [Resources](#resources)&emsp;Previous: [How to play](#how-to-play)&emsp;&emsp;[[Contents](#table-of-contents)]</p>
_Sample of a game on the map "example_small.ber"_

![so_long](https://user-images.githubusercontent.com/80413516/155494401-f80fc365-a149-4cf7-bba0-c28b14634285.gif)

## Resources
###### <p align="right">Next: [Notes](#notes)&emsp;Previous: [Example](#example)&emsp;&emsp;[[Contents](#table-of-contents)]</p>
[MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) made by [hsmits](https://github.com/harm-smits) and @jvan-sni.

Images used from https://opengameart.org/ and https://www.seekpng.com/.

## Notes
###### <p align="right">Previous: [Resources](#resources)&emsp;&emsp;[[Contents](#table-of-contents)]</p>
As there was no wait or sleep function allowed, I did something called "busywaiting" or "spinning" to create time-delays. In general this should not be done because it creates unneeded load on the CPU and the delay is unpredictable (depends on the computer and its workload).
