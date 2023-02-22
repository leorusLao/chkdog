{
    "targets": [{
        "target_name": "chkdog",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "src/api.cpp",
        ],
        "include_dirs": [
            "<!@(node -p \"require('node-addon-api').include\")",
        ],
        "libraries": [],
        "copies": [
            {
                "destination": "./build/Release",
                "files": [
                    "dist/*"
                ]
            }
        ],
        "library_dirs":[],
        "dependencies": [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        "defines": [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
