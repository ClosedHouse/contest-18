TPS aka Test Package Sanity is the essential part of our testing workflow.
We need to guarantee to the customers, that they will be able to install,
rebuild, and uninstall packages without harm.

After some investigation you figured out, that the new package version seems
to be broken. You went to chat  with the developer and you discovered they
decided to use a new cutting edge space characters instead of good old 
tabulators as *separators* inside Makefiles.
(hint: you can take a look to ascii table using:
$ man ascii
and search for \t and SPACE chars)

Makefiles have funny history and during their 'birth' it has been decided
that spaces shall not be used in some parts of the file but in others they
shall not cause any harm.

In our little journey, we need to learn few things about the tested packages
(which are in RPM format on RHEL) - mainly their structure and how to create
a package from a bunch of files.

You were given two so called source packages - these are packages from which
the REAL packages are built from and end with '.src.rpm'. To look inside such
package you need to unpack it first. For that purpose, one can use rpm command:
$ rpm -i my-package.src.rpm

This command will unpack the package into a specific structure located under
'rpmbuild' directory in your home. Here you will find several other directories,
such as BUILD, BUILDROOT, RPMS, and so on. The previous rpm command prepared
your source package to be built, so let's try it - go into the SPECS directory
where you should see a package_name.spec file. That's basically a recipe for
your package. To build a package from that recipe, you can use rpmbuild command:
$ rpmbuild -ba my_package.spec

If the build succeeds, you'll find a brand new RPM under the RPMS directory. If not,
an error will pop up and the rpmbuild will die with a non-zero exit code, giving
you an opportunity to fix the problem a try to build it again. The problem can
be in the recipe itself, or in the package files - these can be found under
the BUILD/package_name... directory (but only if you attempted to build it
at least once).

Now you hopefully know everything you need to know and can try to solve the
puzzle.

Checklist:
    * You should try to rebuild the old and new packages using rpmbuild.
    * Old version works without issues, however the new version is causing you
      troubles.
    * Try to use diff utility to compare both Makefile files.
    * If you manage to fix the issue, you'll find the desired answer you seek.
