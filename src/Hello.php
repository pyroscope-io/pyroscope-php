<?php
$ffi = FFI::cdef(
	"
	typedef long long GoInt;
	GoInt Start(char* applicationName, int cpid, char* spyName, char* serverAddress, char* authToken, int sampleRate, int withSubprocesses, char* logLevel);
	GoInt Stop(int Pid);
	GoInt ChangeName(char* newName, int Pid);
	GoInt RegisterLogger(void* callback);
	GoInt TestLogger();
	",
    "libpyroscope.phpspy.so");

$pid = getmypid();
$ret = $ffi->Start("test_app", $pid, "phpspy", "http://192.168.0.45:4040", "", 100, 0, "Debug");

echo "My pid is: $pid\n";
echo "Start ret is: $ret\n";

$x = 1;
while(true) {
  echo "The number is: $x\n";
  $x++;
  sleep(1);
}
?>
