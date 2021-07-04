
# Rattle-compiler

This is the repository for Rattle language compiler.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

When making commits, follow the commit guide:

### Commit message
```
<type>(<scope>): <summary>
  │       │          │
  │       │          └─⫸ Brief summary of the commit, without a period at its end
  │       │
  │       └─⫸ Commit Scope: lexer|parser|compiler|utils|general
  │                         
  └─⫸ Commit Type: docs|feat|fix|perf|refactor|test
```
Commit summary should start lowercase
#### Type
Must be one of the following:
<ul>
    <li><b>docs:</b> Documentation and comment changes</li>
    <li><b>feat:</b> A new feature</li>
    <li><b>fix:</b> A bug fix (NOTE: if the bug is from a certain commit, write "fixes #&lt;commit_SHA&gt;" before bug description</li>
    <li><b>perf:</b> Code change improving performance</li>
    <li><b>refactor:</b> Purely naming changes or cleanup</li>
    <li><b>test:</b> Adding missing tests or correcting existing tests</li>
</ul>

### Reverting commits

If the commit reverts a previous commit, it should begin with ```revert:```, followed by the header of the reverted commit.

The content of the commit message body should contain:
<ul>
    <li>information about the SHA of the commit being reverted in the following format: "This reverts commit &lt;SHA&gt;"</li>
    <li>a clear description of the reason for reverting the commit message.</li>
</ul>

## License
CC-BY-SA-4.0 