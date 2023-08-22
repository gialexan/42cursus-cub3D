# Cub3D
This is the second graphics project at [42](42sp.org.br).

### What is cub3D?
Cub3D is a team project at [42](42sp.org.br) that asks us to create a "3D" game engine with [miniLibX](https://github.com/42Paris/minilibx-linux). This project is inspired by the world-famous 90's game [Wolfenstein 3D](https://pt.wikipedia.org/wiki/Wolfenstein_3D), which was the first [FPS](https://en.wikipedia.org/wiki/First-person_shooter#:~:text=First%2Dperson%20shooter%20(FPS),in%20a%20three%2Ddimensional%20space.) ever. The objective of this project is to deep dive into the mathematical concepts behind the [ray-casting algorithm](https://en.wikipedia.org/wiki/Ray_casting) such as calculating distances, height, sprite locations and field of view to create a projection using primarily [trigonometry](https://en.wikipedia.org/wiki/Trigonometry).

### Gameplay
![alt text](cub3d.gif)

### Badge
<img src="cub3dm.png" width="150" height="150"/>

#### Skills
- Rigor
- Imperative programming
- Graphics
- Algorithms & AI

#### My grade
<img src="score.png" width="150" height="150"/>


## Getting started
**Follow the steps below**
```bash
# Requirements: X11 miscellaneous extensions library and Utility functions from BSD
# To install the dependencies, open the terminal window and write
sudo apt-get install libxext-dev libbsd-dev
# Clone the project and access the folder
git clone https://github.com/gialexan/42cursus-cub3D && cd 42cursus-cub3D/
# Run make so you can build the game
make
# Run the game with one of these maps as an argument
./cub3D assets/maps/rave.cub
./cub3D assets/maps/dust.cub
# Clean output objects with
make fclean
# Well done!
```

**Game Controller Keys**

**Move player:** W, A, S, D<br />
**Move camera:** 🡠, 🡢 or slide mouse 🡠 and 🡢<br />
**Exit:** ESC

## Updating

The project is regularly updated with bug fixes and code optimization.

---

Made by:<br />
Gilmar Alexandro Romani 👋 [See my linkedin](https://www.linkedin.com/in/gilmar-romani/)<br />
Max Douglas 👋 [See my github](https://github.com/workmadmax)