@echo off
set @fileName=%~1
set @inputDir=%~2
set @outputDir=%~3

echo "building %@inputDir%%@fileName%.mc => %@fileName%.dll"
mc -U "%@inputDir%%@fileName%.mc"
rc -r "%@inputDir%%@fileName%.rc"
link -dll -noentry -out:"%@outputDir%%@fileName%.dll" "%@inputDir%%@fileName%.res"