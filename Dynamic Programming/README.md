<h1></h1>
<h1> What is Dynamic Programming Strategy? </h1>
<p>Dynamic programming and memoization work together. The main difference between dynamic
programming and divide and conquer is that in the case of the latter, sub problems are
independent, whereas in DP there can be an overlap of sub problems. By using memoization
 [maintaining a table of sub problems already solved], dynamic programming reduces the
exponential complexity to polynomial complexity (O(n<sup>2</sup>), O(n<sup>3</sup>), etc.) for many problems. The
major components of DP are:
  <ul>
    <li>Recursion: Solves sub problems recursively.</li>
    <li>Memoization: Stores already computed values in table (Memoization means caching).</li>
  </ul>
  <h3 align = "center"><strong>Dynamic Programming = Recursion + Memoization</sltrong></h3>
</p>

<br>

<h1></h1>
<h1> Properties of Dynamic Programming Strategy </h1>
<p>The two dynamic programming properties which can tell whether it can solve the given problem
or not are:
 <ul>
  <li>Optimal substructure: an optimal solution to a problem contains optimal solutions to sub problems.</li>
  <li>Overlapping sub problems: a recursive solution contains a small number of distinct sub problems repeated many times.</li>
 </ul>
</p>

<br>

<h1></h1>
<h1> Bottom-up V/S Top-down Programming </h1>
<p>In bottom-up programming, the programmer has to select values to calculate and decide the order
of calculation. In this case, all sub problems that might be needed are solved in advance and then
used to build up solutions to larger problems. In top-down programming, the recursive structure
of the original code is preserved, but unnecessary recalculation is avoided. The problem is
broken into sub problems, these sub problems are solved and the solutions remembered, in case
they need to be solved again.
</p>

<br>

<h1></h1>
<h1> Some Examples of Dynamic Programming Algorithms </h1>
<ul>
  <li>Many string algorithms including longest common subsequence, longest increasing subsequence, longest common substring, edit distance.</li>
  <li>Algorithms on graphs can be solved efficiently: Bellman-Ford algorithm for finding the shortest distance in a graph, Floyd’s All-Pairs shortest path algorithm, etc.</li>
  <li>Chain matrix multiplication</li>
  <li>Subset Sum</li>
  <li>0/1 Knapsack</li>
  <li>Travelling salesman problem, and many more</li>
</ul>

<h4 align = "center"> These articles are taken from </h4>
<h3 align = "center"> Data Structures And Algorithms Made Easy </h3>
<h3 align = "center"> By Narasimha Karumanchi </h3>
