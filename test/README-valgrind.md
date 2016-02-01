When using Valgrind, there will be cases that errors are reported
outside of code under test and where no modifications to local
code can resolve the issue.  To resolve these cases, you will want to
research the involved external software and tools to see if
they provide any cleanup() or shutdown() type API's that should be called
before main() exits or if a newer version of software/tools can resolve
the issue.

If that does not solve the Valgrind errors then you will need to
move to using suppression files.  More info on what Valgrind
suppression files are can be found in their manual:
http://valgrind.org/docs/manual/manual-core.html#manual-core.suppress

If a file with name default.supp is found in the test directory, it will be
read by valgrind.  This file can be used for suppression rules that are
common to all $(TESTS) to be ran. If a file with same name as tests
to be ran but with a .supp extension (helloworld -> helloworld.supp) is
found then it will also be read by Valgrind.  This can be used for
suppression rules unique to a single unit test executable.

For your convience, the '--gen-supession=all' option is passed to valgrind so
that a suppression rule is stored allowed with each reported error and can
be copy&pasted into one of the supported suppression files.

When running 'make check', each $(TESTS) will have a matching .log file
and suppression rules will be stored in this log.

When running 'make check-xml', each $(TESTS) will have a matching
-valgrind.xml file and suppression rules will be stored in this log.
Here is example of a suppression rule that could be added to ./default.supp:

    {
       <insert_a_suppression_name_here>
       Memcheck:Leak
       fun:malloc
       fun:_ZN20Hello_test_copy_Test8TestBodyEv
       fun:_ZN7testing8internal38HandleSehExceptionsInMethodIfSupportedINS_4TestEvEET0_PT_MS4_FS3_vEPKc
       fun:_ZN7testing8internal35HandleExceptionsInMethodIfSupportedINS_4TestEvEET0_PT_MS4_FS3_vEPKc
       fun:_ZN7testing4Test3RunEv
       fun:_ZN7testing8TestInfo3RunEv
       fun:_ZN7testing8TestCase3RunEv
       fun:_ZN7testing8internal12UnitTestImpl11RunAllTestsEv
       fun:_ZN7testing8internal38HandleSehExceptionsInMethodIfSupportedINS0_12UnitTestImplEbEET0_PT_MS4_FS3_vEPKc
       fun:_ZN7testing8internal35HandleExceptionsInMethodIfSupportedINS0_12UnitTestImplEbEET0_PT_MS4_FS3_vEPKc
       fun:_ZN7testing8UnitTest3RunEv
       fun:_Z13RUN_ALL_TESTSv
}
