# FredLib
## Header only toolkit to do little things quickly, smally and well

This repo is filled with things I've found myself needing in a lot of projects.
It's not currently meant to be automaticaly included, as there are many files to do differnt things across the entirety of a project, though this may change in the future.
I suspect that only I will ever use this :L

## Things I'd like to do:
+ A nice logging system (but look for existing alternatives first)
+ Re-do `RandomInterface`, as it's way too verbose, and `good rand` is never used
    + Plan all the random functions you want before you start writing
    + Including a system for calcuating binary posibilitys using mulitup dice rolls in a single call (eg. 4d20, or the multi-step issue from my dissertation )
    + Make it so there's a static version of each function to be called for non-thread important things, and member methods for determenistic things
+ A system for running generic jobs in parrallel (formic engine)
+ Let the functions added to `DeferredFunctionQueue` be tagged with a sortable ID, that means function calls can be added in an arbitrary order (for Discrete Event simulation ETC)
