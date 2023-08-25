# lldb-debugging-basics
## Compile for debug
```
c++ -g demo.cpp
```

gcc will compile demo.cpp with debug symbols enabled.

If we are using clang:
```
clang++ -g demo.cpp
```

If you are using cmake take a look at CMAKE_BUILD_TYPE variable.
```
cmake -DCMAKE_BUILD_TYPE=debug <cmake list file> ....
```

## Starting lldb
```
lldb a.out
```

or we can also do:
```
lldb
(lldb)file a.out
(lldb)r
```

### With args
```
lldb -- a.out argument1
```

or we can set arguments in lldb as:
```
settings set -- target.run-args "argument1"
```

### Running
```
(lldb)run
```

```
(lldb)r
```

## Example
In our case we can run our app as below:

```
c++ -g demo.cpp
lldb a.out
```

```
(lldb)r
```

or we can do:
```
lldb -- a.out hello
(lldb)r
```

## Setting Breakpoints
```
(lldb)break set -f demo.cpp -l #
```

or

```
(lldb)br s -f demo.cpp -l #
```

or

```
(lldb)b demo.cpp : #
```

In our case we can do like:
```
(lldb) b demo.cpp : 18
```

### Breakpoints with symbols
#### On a function
```
(lldb)b square(int)
```

#### On a class method
```
(lldb)b Demo::demo()
```

#### Inside a namespace
```
(lldb)b LLDBDemo::add(int, int)
```

### List breakpoints:
```
(lldb)br list
```
### Deleting breakpoints
Deleting specific one
```
(lldb)br del #
```

Delete all the breakpoints
```
(lldb)br del
```

## Stepping around
### Step over
```
(lldb)next
```
or
```
(lldb)n
```

### Step into
```
(lldb)step
```
or
```
(lldb)s
```

### Continue
```
(lldb)c
```

## Inspecting Variables
### Print Variable Contents
```
(lldb)p varName
```

### Frame Variables
```
(lldb)frame variable
```
or
```
(lldb)fr v
```

### Current Line
```
(lldb)frame select
```

## Backtrace & Frames
### Backtrace
```
(lldb)bt
```

### Switching Frames
```
(lldb)frame select 0
```
or 
```
(lldb)f 2
```

## Using Watchpoints
Program must be running in order to set the watchpoint.

### Global Variable
```
(lldb) watchpoint set variable globalVariable
```

```
(lldb) watchpoint set variable -w read | write | read_write globalVariable
```

### Member Variable
```
(lldb) b main
```
```
(lldb) w s v d.memberVar
```