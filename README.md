RGBBot
========
A simple web controlled arduino using Python and a text file


How it works:
--------
1. Webpage sends AJAX call to PHP in order to change .txt file on the server
2. Python contantly polls the .txt file and sends it to the arduino via Serial information
3. The arduino interprates the the Serial information, and lights up the light accordingly

[Diagram](http://25.media.tumblr.com/ef3efde8951830a5785dcc8249dc9d52/tumblr_mvhpb753Ly1rzvzy0o1_500.png)

How to set it up:
--------