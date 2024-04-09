When I first started to learn about machine learning, I wanted to try it out on a simple problem. Connect 4 was the first thing that came to my mind. However, without having much knowledge about complex algorithms and how to implement them, I instead created a tabular model.

In the table, one column had the game's state while the other seven columns had the predicted probability of winning if the AI picked the corresponding action.

![connect4chart](https://github.com/camtamsox/Connect4AI/assets/109252429/bcfa0f44-5b9c-42e4-9245-fb9873baabe8)

_An example of a table with states and their action values._

For each state, the "best" action was the one with the highest predicted probability of winning after doing that action. However, for AI to learn it cannot always play the action it thinks is best. It needs to explore other actions too to figure out if they might be better. So, in its training games where the AI plays against itself, I implemented a system where a certain percentage of the time (20%) the AI picked a random action instead of picking the action it thought was best. This allowed it to learn (by updating the table of predictions) and gain valuable experience from its games.


https://github.com/camtamsox/Connect4AI/assets/109252429/ab6b8448-6341-46af-95eb-dd9f2d9768f3

_An example training game after the AI had trained for 50,000 games (0 is an empty space, 1 is the first AI's disc, 2 is the second AI's disc)._

After playing against the AI myself, I found that the AI wasn't a very strong Connect 4 player. This is because, after only 50,000 games, the AI could not have possibly experienced each possible Connect 4 game state (there are billions of possible states) enough times to know which actions was truly the best.

This shows the need for predicting the action values (the probability of winning from doing this action) without having to experience each possible state many times. A neural network does exactly this by finding patterns in the AI's experience and using these patterns to create an approximation of the action values for each state.


https://github.com/camtamsox/Connect4AI/assets/109252429/4bfe9478-7dfa-41c1-810e-449f3d4a05fe
_Me playing against the AI after 50,000 training games._
