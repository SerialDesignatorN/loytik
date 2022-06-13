# loytik
a small programming language made to entertain myself and being egotistical for me lol

## tutorial how2 compile it urself
u need these following in ur pc

- cmake
- either ninja or make
- gcc or msvc (gcc is recommended)
- a good and familiar knowledge of the terminal or cmd
  
### steps
1. git clone this repo
2. cd to the cloned repo
```
cd loytik
```
3. create a folder called build and cd to it
```
mkdir build && cd build
```
4. compile with cmake from the build directory
```
cmake ..
```
for those of u who are lazy ppls and want to compile with ninja, pass over the `-GNinja` flag

5. either with ninja or make, just type the command to start compilation
```
ninja
```

6. check the demo program on `source/app.lytk` for a demo. to execute it, simply run
```
./loyitik ../source/app.lytk
```
7. enjoy

**note:** to add loyitik to path on linux, simply cp the release or self-compiled to `/usr/bin` or `/usr/local/bin`

# more features coming soon :)