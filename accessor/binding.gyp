{
    "targets": [
        {
            "target_name": "accessor",
            "sources": ["main.cc"],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
