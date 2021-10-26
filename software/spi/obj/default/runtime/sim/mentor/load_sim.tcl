# ------------------------------------------------------------------------------
# Top Level Simulation Script to source msim_setup.tcl
# ------------------------------------------------------------------------------
set QSYS_SIMDIR obj/default/runtime/sim
source msim_setup.tcl
# Copy generated memory initialization hex and dat file(s) to current directory
file copy -force D:/do_an_nhom/SOC_SPI/software/spi/mem_init/hdl_sim/system_onchip_memory2_0.dat ./ 
file copy -force D:/do_an_nhom/SOC_SPI/software/spi/mem_init/system_onchip_memory2_0.hex ./ 
