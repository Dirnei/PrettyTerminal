Param(
    [Parameter(Mandatory = $False)]
    [Switch]$Upload
)
Move-Item .\examples\PrettyTerminal\PrettyTerminal.ino .\examples\PrettyTerminal\PrettyTerminal.cpp

try {
    if ($Upload) {
        pio run -t "upload"
    }
    else {
        pio run
    }
}
finally {
    Move-Item .\examples\PrettyTerminal\PrettyTerminal.cpp .\examples\PrettyTerminal\PrettyTerminal.ino
}