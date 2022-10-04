# ofxGAKit

`ofxGAKit` is the official openFrameworks addon for the `ga::native` toolkit - Gallagher & Associates' in-house C++ toolkit for building interactive experiences.  
It provides your openFrameworks app with a full-featured 3D scenegraph, a powerful animation system, asset management, event handlers, layout utilities, and much more.

## Setup

Like most other oF addons, simply `git clone` this repo inside of your `openFrameworks/addons/` directory:

```sh
cd openFrameworks/addons
git clone --recursive https://github.com/gallagher-tech/ofxGAKit
```

_If you missed the `recursive` flag when cloning, use following command to get the ga::kit submodule:_

```sh
git submodule update --init --recursive
```

Then use the oF Project Generator to generate a project with `ofxGAKit` selected.

## [ga::kit](https://github.com/gallagher-tech/gaKit/)?

`ga::kit` is G&A's in-house C++ application framework for building interactive experiences.  
We use it to create anything from 2D UI prototypes to high-performance 3D immersive installations.

You can find more information on the library [here](https://github.com/gallagher-tech/gaKit/blob/main/README.md).

## Features

- Hierarchical 3D **Scenegraph** with `Scene`, `Node`, and `Component` classes
- Innovative **tween animation system** with `Tween`, `Timeline` and easing functions
- `Timer` and `Timeout` classes for triggering timed callbacks
- Universal app **asset management** with templated `ResourceCache` class
- `KeyEvent`, `MouseEvent` and `TouchEvent` handling
- **Layout** utitilies to automatically align and scale to fit
- Math utilities built on [**glm**](https://github.com/g-truc/glm)
- JSON serialization, using [**nlohmann::json**](https://github.com/nlohmann/json)
- Signal-based event system, using [**sigslot**](https://github.com/palacaze/sigslot) (included)
- Universal Unique ID system, using [**crossguid**](https://github.com/graeme-hill/crossguid) (included)

## Todo

- GLSL `Shader` class
- `Material` (shader + textures + parameters) component
- `Mesh` VBO component
- Cinder block
- Framework-free example using GLFW

## Requirements

- C++11
- OpenGL 3+
- [**glm**](https://github.com/g-truc/glm)
- [**nlohmann::json**](https://github.com/nlohmann/json)
