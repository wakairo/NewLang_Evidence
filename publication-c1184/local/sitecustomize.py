"""P-owned measurement only; does not change compiler arguments or results."""
import os
from pathlib import Path
import subprocess
from meterlib import record, finish

_original=subprocess.Popen
class MeteredPopen(_original):
    def __init__(self,args,*a,**kw):
        self._p1525_id=None
        if isinstance(args,(list,tuple)) and args:
            exe=Path(str(args[0]))
            if exe.name in ('newlangc','p1517_cli_fault'):
                self._p1525_id=record('nested CLI',args)
            elif ('/p1517-native/' in str(exe) or '/p1507-native/' in str(exe)) and '-O' in exe.name:
                env=kw.get('env') or os.environ
                self._p1525_id=record('selected guest',args,native=1,fail_at=env.get('P1517_FAIL_AT',env.get('P1507_FAIL_AT')))
        super().__init__(args,*a,**kw)
    def communicate(self,*a,**kw):
        result=super().communicate(*a,**kw)
        if self._p1525_id is not None:
            finish(self._p1525_id,self.returncode,*result)
            self._p1525_id=None
        return result
subprocess.Popen=MeteredPopen
