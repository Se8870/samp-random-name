# random-name

[![sampctl](https://img.shields.io/badge/sampctl-random--name-2f2f2f.svg?style=for-the-badge)](https://github.com/Kirima2nd/samp-random-name)

SA-MP Random Name taken from Python source code which is you can find it below:

https://github.com/treyhunner/names

All credits goes to right code owner, treyhunner.

## Installation

Simply install to your project:

```bash
sampctl package install Kirima2nd/samp-random-name
```

Include in your code and begin using the library:

```pawn
#include <random-name>
```

### **NOTE**: 

since sampctl doesn't support scriptfiles, you'll have to manually move the scriptfiles to your project
or if you're not sampctl user, you can just ignore this message.

## Function Lists

```pawn
native GetFirstName(gender = GENDER_NONE);
native GetLastName();
native GetRandomName(gender = GENDER_NONE, bool:underscore = false);
```

## Usage

You can check it on test.pwn

## Testing

To test, simply run the following commands:

```bash
sampctl package ensure
sampctl package run --forceBuild
```

