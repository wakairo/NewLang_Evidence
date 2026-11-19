from pathlib import Path
from meter import run,E
W=Path('/workspace/NewLang_P1535');cm='/workspace/newlang-tools/bin/cmake'
run('existing GCC exact version',['/usr/bin/gcc','--version'])
run('configure fresh normal Release fortified frontend',[cm,'-S',W,'-B',E/'build-gcc','-DNEWLANG_FRONTEND_ONLY=ON','-DBUILD_TESTING=ON','-DCMAKE_BUILD_TYPE=Release','-DCMAKE_C_COMPILER=/usr/bin/gcc','-DCMAKE_C_FLAGS=-D_FORTIFY_SOURCE=2'])
run('single GCC frontend build exact formatted582 plus existing API agreement probe',[cm,'--build',E/'build-gcc','--target','newlangc','p1529_consumer','--verbose','-j2'],frontend=1)
run('single unchanged GCC public-only owned probe build',[cm,'--build',E/'build-gcc','--target','p1535_public_owned','--verbose','-j2'],probe=1)
