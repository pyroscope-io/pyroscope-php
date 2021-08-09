--TEST--
Check if pyroscope is loaded
--EXTENSIONS--
pyroscope
--FILE--
<?php
echo 'The extension "pyroscope" is available';
?>
--EXPECT--
The extension "pyroscope" is available
