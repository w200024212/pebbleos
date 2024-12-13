Header Overrides for Unit Tests
===============================

Writing a test which requires overriding a header?
--------------------------------------------------

1. Create a new override tree with versions of the headers you want to
   override.  Only the header files you add to this tree will shadow
   default override headers and source-tree headers.
2. Create header files in subdirectories under this override tree so
   that the relative paths to the override headers mirrors that of the
   source tree. For example, if the header you want to override is
   included by

   ```c
   #include "applib/ui/ui.h"
   ```
   
   then the override file should be placed in
   `tests/overrides/my_override/applib/ui/ui.h`
3. Specify the override tree in your test's build rule.

   ```python
   clar(ctx, ..., override_includes=['my_override'])
   ```

Guidelines for writing an override header
-----------------------------------------

### Never include function prototypes in an override header. ###

It is too easy to change a function prototype in a firmware header but
forget to mirror that change in an override header. Tests could start
erroneously failing when there is nothing wrong with the code, or
(worse) tests could erroneously pass when the code contains errors.
Refactor the header so that the header itself contains function
prototypes and the inline function definitions are placed in a separate
`header.inl.h` file. At the bottom of the header file,

```c
#include "full/path/to/header.inl.h"
```

and provide an override header for just `header.inl.h`.
