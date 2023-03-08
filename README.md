<div align="center">
  <p>
    <a align="center" href="https://github.com/gallagher-tech/ofxGAkit" target="_blank">
      <img width="100%" src="banner.jpg"></a>
  </p>

# ofxGAkit

</div>

| [ofxGAkit Repo](https://github.com/gallagher-tech/ofxGAkit) | [GA::kit Repo](https://github.com/gallagher-tech/GAkit/) | [Documentation](https://gallagher-tech.github.io/GAkit-doc/) |

`ofxGAkit` is the official openFrameworks addon for the `GA::kit` toolkit - G&A' in-house C++ toolkit for building interactive experiences.  
It provides your openFrameworks app with a full-featured 3D scenegraph, a powerful animation system, asset management, event handlers, layout utilities, and much more.

## Setup

Like most other oF addons, simply `git clone --recursive` this repo inside of your `openFrameworks/addons/` directory:

```sh
cd openFrameworks/addons
git clone --recursive https://github.com/gallagher-tech/ofxGAkit
```

_If you missed the `recursive` flag when cloning, use following command to get the GA::kit submodule:_

```sh
git submodule update --init --recursive
```

Then use the oF Project Generator to generate a project with `ofxGAkit` selected.

_Additionally, if you are looking for a development branch of `GA::kit`, use the following commands to checkout the desired branch after the steps above:_

```sh
cd libs/gaKit
git checkout [BRANCH_NAME]
```

**This addon has been tested to work on Windows 10/11.**

## [GA::kit](https://github.com/gallagher-tech/GAkit/)?

`GA::kit` is G&A's in-house C++ application framework for building interactive experiences.  
We use it to create anything from 2D UI prototypes to high-performance 3D immersive installations.

You can find more information and documentation [here](https://gallagher-tech.github.io/GAkit-doc/).

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

## About G&A

We are the industry’s best strategic problem solvers. A team of boundless creative individuals. As experts in our own craft, relentless curiosity fuels our passion for working with the best partners to build community experiences led by their profound stories. Bring your story and become part of ours.

Visit G&A [website](https://gallagherdesign.com/)
