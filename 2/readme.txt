Security is an important part of IT systems. Red Hat provides security updates
to customers which need to be tested as well.

In many cases these updates are for server-client applications. To test
such applications we need to simulate the server and client environments.

For this scenario you were given client and server environments, and an urgent
report from a customer, that the client application sends passwords in
a plain text. As you surely know, this is a serious security issue and needs
to be fixed ASAP, to prevent possible attackers from discovering your passwords.

You have the old version, which does have this vulnerability and a new version
from the developer, which should be fixed. Now everything depends on your
ability to test whether the new version is indeed properly patched.

According to the documentation you should try to listen on port 8088. For that
purpose you can use netcat (nc command)

With this knowledge test if the old version indeed sends the passwords in
a plain text and the new does not. Also, look for possible changes in response
headers.
