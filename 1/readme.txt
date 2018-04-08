TPS aka Test Package Sanity is essential part of our testing workflow.
We need guarantee to customers, that they will be able to install, rebuild and uninstall packages without harm.

After some investigation, you figured out, that new version of package seems to be broken. You talked with developer and they decided to use new cutting edge
space chars instead of good old tabulators as *separators* inside Makefile 
(hint: you can take a look to ascii table: $ man ascii and search for \t and SPACE chars) inside Makefile.

Makefile have funny history and once while desinging there has been decided thatspaces will not be used in some part of file.

* potrebujeme dalsi veci o tom, jak vypada build root a jak pouzit rpmbuild *

Checklist:
	* You should try to rebuild old and new package with rpmbuild.
	  Old version works without troubles however new version doesn't
	  want to build.
	* Try do use diff util to compare both Makefile files.
	* Try to fix it and then you fill answer


Build of package failed because:
a) there has been aliens hidden inside spec file


