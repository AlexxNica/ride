# Ride
Ride is a Rust IDE. It's named after concatenating R from rust and IDE. It's currently not in a usable state.

The project aim is to implement as much of it in C++ and then port it to rust when it stabilizes.

![screenshot](screenshots/1.png)

# Unsorted Roadmap

* Mark important "word" for highlighting
* Highlight misspelled words/comments
* Make output window use scintilla and styling
* Function for selecting current word
* Remember session data
* Goto definition & goto definition of type
* Expose all scintilla settings in gui + settings
* Detect changes outside ride and ask to reload file
* Comment / uncomment selection
* Expose all aui settings in gui + settings
* Switch tabs by scrolling with cursor over tab-bar
* Scintilla text commands (edit->select all, etc)
* Sort selected lines
* Align/remove space left/right
* Trim left/right/both selected lines
* Format file/selection
* Color member variables, local variables and member variables different.
* Find in files, find in solution, incremental search, other searches
* Fix syntax scintilla syntax highlighting
	- wxWidgets [doesn't support](http://trac.wxwidgets.org/ticket/16776)  rust yet, perhaps temporarily solve it with conditional compilation with a cpp lexer and rust keywords
* Project/solution explorer
* Create project with cargo and add a README.md file
* Error list
* Start page
* Startup options (open homepage, load last loaded project, show open project dialog box, show new project dialog box, show empty enviroment, show start page)
* Project file so we can open project with File->Open
* Option to force charset, lineending and ending with newline when saving
* Visual studio like debug settings
* Context menu support
* Go to next error shortcut
* Quick open file from solution/project
* Simple/basic git commit shortcut with specifying the commit message
* Cpack support (=installer for ride)
* Intellisense/autocomplete support via [racer](https://github.com/phildawes/racer)
* Investigate debugging support (gdb?)
* Custom styles (like zenburn, obsidian, ...)
* Import styles from other editors (like visualstudio / https://studiostyl.es/ )
* Code snippets
* View documents inline instead of in a new tab
* File templates
* Numbered bookmarks
* Implement ctrl+tab like visual studio to switch between open documents
* Open type in online documentation command/do a search...
* Search google for this compiler error
* Built in syntax highlight for shading languges like glsl like http://nshader.codeplex.com/

# Debug ideas

- Color tint IDE depending on current thread executing?
- Add note to code (when debugging) to comeback to later
