Security is important part of IT systems. Red Hat provides security updates to customers.
We are testing security too.

You have client and server environment and there has been reported that client application sends
password in open form which attacker can read.

Old version of client sent plain text password. New version should send encrypted password which you should test. Try to listen with netcat on port 8088 and investigate if developer sucesfully patched application.

You also should take a look at new items in header.
