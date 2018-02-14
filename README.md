#libcallistashared

This library provides the core UI framework behind all Callista Suite applications.

Any UI-related code that may be reusable among multiple applications should go here - for example, windowing code and layer management would go here, but a timeline for a video editor would *not*.

This library is released under the MIT license, so feel free to take it apart and reuse it, although I doubt anyone will have much use for this outside of making Callista applications :D

## Technical info

So, this library is statically linked into each individual application. Static linking just makes things so much easier in terms of distribution.

The only backend being worked on right now is GTK+-3.0; there are planned backends for Windows Universal or Win32 C++ (not sure yet), as well as Cocoa, but these haven't been started yet.