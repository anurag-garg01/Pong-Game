
# Pong Game

Pong Game is an open-source multiplayer Pong game built using C++ and OpenGL. It recreates the classic Pong arcade game where two players control paddles to hit a ball back and forth across the screen.



## Features

- Multiplayer functionality allowing two players to compete against each other.
- Simple and intuitive controls using keyboard inputs.
- Real-time ball physics and collision detection.
- Score tracking for each player.
- Colorful and visually appealing graphics using OpenGL.


## Requirements

To run this game, you need to have the following:

- C++ compiler supporting C++11 or later.
- OpenGL libraries and dependencies.
- FreeGLUT library for window management.
## Installation

 Clone the repository:

```bash
  git clone https://github.com/anurag-garg01/Pong-Game.git
```

Compile the source code using the following command:

```bash
  g++ -std=c++11 main.cpp -o PongGame -lGL -lGLU -lglut
```

Run the executable:

```bash
  ./PongGame
```
## Usage

- Use the W and S keys to control the left paddle.
- Use the up and down arrow keys to control the right paddle.
- The game starts automatically when launched.
- Each time the ball hits a paddle, it changes direction.
- The game ends when one of the players reaches the maximum score.



## Contributing

Contributions are welcome! If you want to contribute to this project, please follow these steps:

- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make the necessary changes and commit them.
- Push your changes to your forked repository.
- Submit a pull request to the main repository.

Please ensure your code follows the project's coding conventions and includes appropriate documentation.
