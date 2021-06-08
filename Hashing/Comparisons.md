<h1 align = "center"> Linear Probing vs. Double Hashing </h1>
<p>The choice between linear probing and double hashing depends on the cost of computing the hash
function and on the load factor [number of elements per slot] of the table. Both use few probes but
double hashing take more time because it hashes to compare two hash functions for long keys.</p><br>

<h1 align = "center"> Open Addressing vs. Separate Chaining </h1>
<p>It is somewhat complicated because we have to account for the memory usage. Separate chaining
uses extra memory for links. Open addressing needs extra memory implicitly within the table to
terminate the probe sequence. Open-addressed hash tables cannot be used if the data does not
have unique keys. An alternative is to use separate chained hash tables.</p><br>

<h1 align = "center">Comparisons: Open Addressing methods</h1>
<table align = "center" border = "1" cellspacing = "10" cellpadding = "10">
  <tr>
    <th align = "center"><b>Linear Probing</b></th>
    <th align = "center"><b>Quadratic Probing</b></th>
    <th align = "center"><b>Double Hashing</b></th>
  </tr>
  <tr>
    <td align = "center">Fastest among three</th>
    <td align = "center">Easiest to implement and deploy</th>
    <td align = "center">Makes more efficient use of memory</th>
  </tr>
  <tr>
    <td align = "center">Uses few probes</th>
    <td align = "center">Uses extra memory for links and it does not probe all locations in the table</th>
    <td align = "center">Uses few probes but takes more time</th>
  </tr>
  <tr>
    <td align = "center">A problem occurs known as primary clustering</th>
    <td align = "center">A problem occurs known as secondary clustering</th>
    <td align = "center">More complicated to implement</th>
  </tr>
  <tr>
    <td align = "center">Interval between probs is fixed - often at 1</th>
    <td align = "center">Interval between probes increases proportional to hash value</th>
    <td align = "center">Interval between probes is computed by another hash function</th>
  </tr>
</table>
