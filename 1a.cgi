#!/usr/bin/perl
print "content-type:text/html","\n\n";
print "<html><title>result of io</title>","\n";
use CGI':standard';
use DBI;
$dbh=DBI->connect("DBI:mysql:test1","root","");
$name=param("name");
$age=param("age");
$qh=$dbh->prepare("insert into stud values('$name','$age')");
$qh->execute();
$qh=$dbh->prepare("select * from stud");
$qh->execute();
print "<table border size=1><caption>si</caption><tr><th>name</th><th>age</th></tr>";
while(($name,$age)=$qh->fetchrow())
{
print "<tr><td>$name</td><td>$age</td></tr>";
}
print "</table>";
$qh->finish();
$dbh->disconnect();
print "</html>";

