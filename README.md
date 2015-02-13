# Ride
Ride is a Rust IDE. It's named after concatenating R from rust and IDE. It's currently not in a usable state.

The project aim is to implement as much of it in C++ and then port it to rust when it stabilizes.

# Unsorted Roadmap

* Create filter list from known languages
* Expose all scintilla settings in gui + settings
* scintilla text commands (edit->select all, etc)
* Indenting feature: None, block, smart
* Find in files, find in solution, incremental search, other searches
* Fix syntax scintilla syntax highlighting
	- wxWidgets [doesn't support](http://trac.wxwidgets.org/ticket/16776)  rust yet, perhaps temporarily solve it with conditional compilation with a cpp lexer and rust keywords
* project/solution explorer
* project/solution(=cargo) commands
* start page
* build output
* error list
* visual studio like debug settings
* context menu support
* go to next error shortcut
* quick open file from solution/project
* remember opened file since last time
* cpack support (=installer for ride)
* Intellisense/autocomplete support via [racer](https://github.com/phildawes/racer)
* investigate debugging support (gdb?)
* custom styles (like zenburn, obsidian, ...)
* import styles from other editors (like visualstudio / https://studiostyl.es/ )
* code snippets
* file templates
* numbered bookmarks
* built in syntax highlight for shading languges like glsl like http://nshader.codeplex.com/

# Debug ideas

- Color tint IDE depending on current thread executing?
- Add note to code (when debugging) to comeback to later
