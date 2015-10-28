{
    "targets": [
        {
            "target_name": "oTemplate",
            "sources": ["main.cc"],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
