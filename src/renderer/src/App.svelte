<script>
    import TitleBar from "./components/TitleBar.svelte";
    import Emulator from "./components/Emulator.svelte";
    import SideBar from "./components/SideBar.svelte";
</script>

<TitleBar />
<div class="content">
	<SideBar />
	<Emulator />
</div>

<style lang="scss">
@import "Config.scss";

.content {
	display: flex;
	flex-direction: row;
	justify-content: space-between;
}
</style>