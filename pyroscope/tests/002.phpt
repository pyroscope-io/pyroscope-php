--TEST--
test1() Basic test
--EXTENSIONS--
pyroscope
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension pyroscope is loaded and working!
NULL
