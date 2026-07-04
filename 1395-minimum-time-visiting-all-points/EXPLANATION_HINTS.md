Discussion 1-> was asked this problem during my interview with Facebook. The problem asks us to visit the points in the same order as they appear in the array. So I finished it in 5 min. Then I was asked the follow up question: what if we don't need to visit points in order? What if we can choose whatever point to visit? How should we find the minimum time to visit every point? My naive thinking is Dijkstra's algorithm or A* algorithm, but maybe Dijkstra's algorithm or A* algorithm won't work for such a follow up? I struggled to find a way to solve the follow up question but not successful. Any thoughts about it?<br>
<br>Discussion 2->When solving this problem, it's essential to make the most of diagonal movement. For example, when moving from point [1,1] to [3,4], First calculate the differences in both x and y coordinates: dx = 3 - 1 = 2 and dy = 4 - 1 = 3. You can move diagonally for the minimum of these two values, which is 2 times in this case. After these diagonal moves, you have one remaining vertical move to reach [3,4], because the difference in y-coordinate is still 1 after accounting for the diagonal moves. The total time for each segment is the maximum of dx and dy, as this combines diagonal movement with any remaining horizontal or vertical movement needed.




# Why the Answer is `max(dx, dy)` — Building the Intuition

> Notes on [1266. Minimum Time Visiting All Points](https://leetcode.com/problems/minimum-time-visiting-all-points/)

This is exactly the kind of thing that's easy to prove but hard to *feel* until it clicks. Let's build it up from scratch.

## Start with the actual constraint

You have two independent "jobs" to finish:

- Close the horizontal gap: `dx` units
- Close the vertical gap: `dy` units

Every second, you get to chip away at **one or both** of these jobs, because a diagonal move does 1 unit of horizontal progress AND 1 unit of vertical progress **for free, in the same second**.

So a diagonal move isn't "cheating" — it's just doing two jobs at once instead of one.

## The key reframe: two workers sharing a clock

Imagine `dx = 2` and `dy = 3`. Picture two counters that need to hit zero:

```
horizontal counter: 2, 2, 2, ...
vertical counter:   3, 3, 3, ...
```

Each second, you get to decrement **either one or both** counters by 1 (that's what horizontal-move / vertical-move / diagonal-move means in terms of progress). You want both counters at 0 as fast as possible.

Obviously, as long as *both* counters are still above zero, you should move diagonally — decrementing both at once is strictly better than only decrementing one, since it makes progress toward both goals for the same cost of "1 second." There's never a reason to waste a second only closing one gap if the other gap still needs closing too.

So you diagonal-step until the **smaller** counter (here, `dx = 2`) hits zero. That takes `min(dx, dy)` seconds. During those same `min(dx, dy)` seconds, the larger counter also dropped by that same amount (since every diagonal step reduces both). So the larger counter now has `dy - dx` left (i.e., `max - min` remaining).

Now one job is done, and you're left with pure leftover work on the other axis: `max(dx, dy) - min(dx, dy)` more single-direction steps.

Total time = (steps spent doing both jobs at once) + (steps spent finishing the leftover job)

```
= min(dx, dy) + (max(dx, dy) - min(dx, dy))
= max(dx, dy)
```

The `min` cancels out! That's the "aha" — the diagonal phase and the leftover phase together **always** sum to exactly the bigger of the two numbers, no matter how you look at it.

## An even more visual way to see it

Draw a `dx × dy` rectangle grid, going from the start corner to the end corner. A diagonal move is like sliding along the actual diagonal of that grid, one unit at a time. You can only diagonal-slide as far as the *shorter side* lets you (you run out of room in that direction). After that, you're walking straight along the longer side by yourself.

So visually: diagonal across the short dimension, then straight along the extra length of the long dimension. The number of steps is just... the length of the long dimension, because the diagonal phase was "absorbed" into it.

## Sanity check with an example

`dx = 2, dy = 3`:

- Step 1: diagonal `(2,3) → (1,2)` — both counters -1
- Step 2: diagonal `(1,2) → (0,1)` — both counters -1 — now `dx` is 0, `dy` is 1
- Step 3: vertical only `(0,1) → (0,0)`

3 steps total = `max(2, 3)`. Exactly matches. ✅

## The core intuition, in one sentence

> Diagonal moves let you pay for two directions with one second, so you should always use them while both directions still owe you distance — and once the shorter debt is paid off, you're stuck paying the rest of the longer debt one unit at a time, and that total naturally equals the bigger number.
