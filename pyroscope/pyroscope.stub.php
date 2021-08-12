<?php

/** @generate-class-entries */

function start(string $applicationName, int $cpid, string $spyName, string $serverAddress, string $authToken, int $sampleRate, int $withSubprocesses, string $logLevel): int {}
function stop(int $pid): int {}
function changeName(string $newName, int $pid): int {}
