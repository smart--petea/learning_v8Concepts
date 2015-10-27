{
    "targets": [
        {
            "target_name": "fTemplate",
            "sources": ["main.cc"],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
